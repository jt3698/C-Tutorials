#include<bits/stdc++.h>

using namespace std;

struct Barang{
	int harga;
	string nama;
	int idx;
} barang[1005];

bool cmpharga(Barang a, Barang b)
{
	if(a.harga > b.harga) return 1;
	else if(a.harga == b.harga) return a.nama < b.nama;
	return 0;
}

int main()
{
	int N,M;
	cin>>N>>M;

	for(int i=1;i<=N;i++){
		cin>>barang[i].nama>>barang[i].harga;
		barang[i].idx=i;
	}

	sort(barang+1,barang+N+1,cmpharga);

	for(int i=1;i<=N;i++)if(barang[i].harga<=M){
        cout<<barang[i].nama<<" "<<barang[i].idx<<endl;
        M-=barang[i].harga;
    }

	return 0;
}
