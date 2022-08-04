#include <iostream>
#include <random> 
using namespace std;

int main() {
  //全体のカードの配列
  int card[52];
  //ディーラーのカードの配列  
  int dCard[52]; 
  //プレイヤーのカードの配列  
  int pCard[52];

  //乱数生成用
  int i;
  int a;
  int b;
  int c;

  //ディーラーの引いたカードの合計数
  int Dsum = 0;

  int e = 0;//ディーラーが引く数
  int pD = 0;//プレイヤーのカードの配列の要素をずらす用変数
  int p = 1; //全体のカードの配列から、プレイヤーが引くカードの調整用変数
  int pCardS = 0;//プレイヤーがカード引いた数

  int pSum =0;//プレイヤーが引いた数の合計数


  int drawS;  //ドローされたかどうかの確認用変数  
  bool victory = false;  //かったかどうかのフラグ
  bool lose = false;//まけたかどうかのフラグ

  int pK;//掛け金

  bool doubleUp = false;//ダブルアップしたかどうか
  int doubleUpInt = 0;//ダブルアップフラグを受け入れる変数
  
  cout<<"掛け金を入力してください"<<endl;
  cin>>pK; 

     /* 配列（トランプ）初期化 */
    for( i=0; i<52 ; i++ ){
      card[i] = i+1;
    }
    srand( (int)time(NULL));
    /* トランプを切る */
    for( i=0; i<52; i++ ){
      a = rand() % 52;
      b = rand() % 52;
      c = card[a];
      card[a] = card[b];
      card[b] = c;
    }
    
    //上の数字を13でわる
    for( i=0; i<52 ; i++){
      int t = (card[i]%52)/13;
      int a = card[i]%12+1;
      switch(t){
        case 0:
          card[i] = a;
        break;
        case 1:
          card[i] = a;
        break;
        case 2:
          card[i] = a;
        break;
        default:
          card[i] = a;
        break;
      }
    }

   //ディーラーの操作
    while(Dsum <= 20){
      //全体のカード配列からカードを持ってくる
        dCard[e]=card[e];
      //合計数を求める
        Dsum += dCard[e];
        e++;      
    }

    //合計数の表示  
    cout<<"相手の合計数："<<Dsum<<endl; 

  //ディーラーの合計数が26より大きかったら勝つ  
    if(Dsum >26){
      cout<<"あなたの勝ちです"<<endl; 
      victory = true;
      pK *=1.5;
    }

  //ディーラーの合計数が26だったら負ける
    if(Dsum == 26){
      cout<<"あなたの負けです"<<endl; 
      lose = true;
      pK-=pK;
    }

    //プレイヤーが2枚引く操作
    if(victory == false && lose == false && pCardS <2){
        pCard[1 + pD] = card[e+p];
        cout<<pCard[1 +pD]<<endl; 
        //プレイヤーカードの合計数        
        pSum += pCard[1 +pD];
        //配列の要素を一つずらす        
        pD++;
        p++;
        pCardS++;
    }



  //カードをひく場合
    if(victory == false && lose == false){
      //プレイヤーの合計数が26少ない時
      cout<<"合計"<<pSum<<endl;
      while(pSum<26)
      {
        cout<<"ダブルアップをしますか？"<<endl;  
        cout<<"引くなら1 引かないなら2を押してください"<<endl;  
        cin >> doubleUpInt;
        if(doubleUpInt == 1){
          //プレイヤーカード配列に値を記憶させる
          pCard[1 + pD] = card[e+p];
          cout<<pCard[1 +pD]<<endl; 
          //プレイヤーカードの合計数        
          pSum += pCard[1 +pD];
          //ダブルアップしたのでフラグを立てる
          doubleUp = true;      
          cout<<"合計"<<pSum<<endl;
        }

        cout<<"カードを引きますか？"<<endl;
        cout<<"引くなら1 引かないなら2を押してください"<<endl;  
        cin>>drawS; 
        //プレイヤーがカードを引いた時
        if(drawS == 1){
        //プレイヤーカード配列に値を記憶させる
        pCard[1 + pD] = card[e+p];
        cout<<pCard[1 +pD]<<endl; 
        //プレイヤーカードの合計数        
        pSum += pCard[1 +pD];
        //配列の要素を一つずらす        
        pD++;
        p++;
        cout<<"合計"<<pSum<<endl;
        doubleUp = true;   
        //26になったらこの文全体を抜ける
          if(pSum == 26){
            continue;
          }        
        }else{
          doubleUp = true;      
          continue;
        }
      }
    }

    //プレイヤー合計数が26だったら    
    if(pSum == 26){
      cout<<"あなたの勝ちです"<<endl;
      victory = true;
      if(doubleUp == true){
        pK*=2;
      }else{
        pK *=1.5;
      }
    }

  //プレイヤー合計数が26以上だったら
    if(pSum > 26)
    {
      cout<<"あなたの負けです"<<endl; 
      lose = true;
      pK-=pK;
    }
  
    //上のif文に入らなかった場合の処理
    if(victory == false && lose == false){
      if(Dsum >= pSum){
        cout<<"あなたの負けです"<<endl; 
        pK-=pK;
      }else if(Dsum == pSum){
        cout<<"引き分けです"<<endl; 
      }else{
        cout<<"あなたの勝ちです"<<endl; 
        pK *=1.5;
      }
    }
}