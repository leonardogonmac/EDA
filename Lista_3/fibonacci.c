
long int fibonacci (int n){
    if(n == 2 || n == 1){
        return 1;
    }

    static int lim = 3;
    static long int n1 = 1;
    static long int n2 = 1;
    static long int n3;

    if(lim <= n){
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        lim++;
        fibonacci(n);
    }
    return n3;

}