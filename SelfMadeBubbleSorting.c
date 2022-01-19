void exchange(int * tr,int i , int j){
    int temp;
    
    temp = tr[i];
    tr[i] = tr[j];
    tr[j] = temp;
}

void sort_by_area(int n, int *y) {
    int i , x ,g, flag = 0;
    
    for ( i = 0 ; i < n ; i++){
        g = i;
        for ( x = i + 1; x < n; x++){
            if ( y[i] > y[x] ){
                flag = 1;
                exchange(y, i, x);
                i = x;
            }
        }
    if (flag == 1){
        i = g - 1;
        flag = 0;}
    }
}
int main()
{
	int n;
	scanf("%d", &n);
	int x [10];
	for ( int i = 0; i < 10 ; i++){
	    scanf("%d",&x[i]);
	}
	sort_by_area(10 , x);
	for ( int i = 0; i < 10 ; i++){
	    printf("%d\n",x[i]);
	}
	return 0;
}
