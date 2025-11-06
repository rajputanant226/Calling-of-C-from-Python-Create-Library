//gcc -std=c11 -o customlib1.so --shared -fPIC Functions.c
int lcm(int a,int b){
    int l;
    for(l=a>b?a:b;l<=a*b;l++){
        if(l%a==0 && l%b==0){
            return l;
        }
    }
}
int fact(int n){
    int f=1;
    for(int i=1;i<=n;i++){
        f=f*i;
    }
    return f;
}