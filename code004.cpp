#include <iostream>

using namespace std;

int main(void){
  int h,w;
  cin >> h >> w;
  int *a = (int *)malloc(h*w*sizeof(int));
  int *o = (int *)malloc(h*w*sizeof(int));
  int *hl = (int *)malloc(h*sizeof(int));
  int *wl = (int *)malloc(w*sizeof(int));
  for(int y=0; y<h; y++)
    for(int x=0; x<w; x++)
      cin >> *(a+y*w+x);
      
  //line前処理
  for(int y=0; y<h; y++)
    for(int x=0; x<w; x++){
      *(hl+y) += *(a+y*w+x);
      *(wl+x) += *(a+x+y*w);
    }
  
  for(int y=0; y<h; y++)
    for(int x=0; x<w; x++){
      *(o+y*w+x) += *(hl+y)+*(wl+x)-*(a+y*w+x); //自カウント分
      
    }
    
  for(int y=0; y<h; y++){
    for(int x=0; x<w; x++){
      cout << *(o+y*w+x) << " ";
    }
    cout << endl;
  }
  
  free(a); free(o); free(wl); free(hl);
  
  return 0;
}