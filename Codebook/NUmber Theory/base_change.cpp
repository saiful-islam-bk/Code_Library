//10-base to m-base:
String a= "0123456789ABCDE";
string tenToMbase(int n, int m){
  int temp=n; string result="";
  while (temp!=0){
    result=a[temp%m]+result; temp/=m;
  }
  return result;
}

//m-base to 10-base:
string num="0123456789ABCDE";
int mToTen(string n, int m){
  int multi=1, result=0;
  for(int i=n.size()-1; i>=0; i--){
    result+=num.find(n[i])*multi;
    multi*=m;
  }
}
