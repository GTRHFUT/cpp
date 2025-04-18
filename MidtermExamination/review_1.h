//最大公约数
int Hcf_1(int m, int n){
    if(n == 0)return m;
    return Hcf_1(n, m % n);
}
int Hcf_2(int m, int n){
    int r = 0;
    while(n){
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}