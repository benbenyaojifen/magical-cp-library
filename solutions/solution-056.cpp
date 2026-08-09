#include "stdc.h"

int main(){
    vector<int> vec;
    for(int i = 0;; i++){
        int range = pow(i, 6);
        if(range > 1e8) break;
         vec.push_back(range);
    }
    int a, b;
    cin >> a >> b;
    int cnt, l, r;
    l = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
    r = upper_bound(vec.begin(), vec.end(), b) - vec.begin();
    cnt = r - l;
    cout << cnt << endl;
}
//faster solution using scanf
/*
#include <stdio.h>
#include <math.h>

int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);

	int i = 0;
	int count = 0;
	while (pow(i,6) <= b) {
		if (pow(i,6) >= a) count++;
		i++;
	}

	printf("%d\n",count);

	return 0;
}*/