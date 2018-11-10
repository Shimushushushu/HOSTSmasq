#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxx 100010
#define maxxx 256

using namespace std;

struct node
{
	int ip[4];
	unsigned long long ip_hash;
	char ad[maxxx];
} addr[maxx];

int cmp_2(const void *a,const void *b)
{
	struct node *aa=(node *)a;
	struct node *bb=(node *)b;
	if(aa->ip_hash==bb->ip_hash) return 0;
	else if(aa->ip_hash<bb->ip_hash) return -1;
	return 1;
}

int n=0,i=1,j=1,k=0;

int main()
{
	freopen("hosts","r",stdin);
	freopen("dnsmasq.conf.add","w",stdout);
	while(scanf("%d.%d.%d.%d %s",
		&addr[n].ip[0],&addr[n].ip[1],&addr[n].ip[2],&addr[n].ip[3],addr[n].ad)!=EOF)
	{
		addr[n].ip_hash=addr[n].ip[3]+(addr[n].ip[2]<<8)+(addr[n].ip[1]<<16)+(addr[n].ip[0]<<24);
		n++;
	}
	qsort(addr,n,sizeof addr[0],cmp_2);

	i=1,j=1;
	while(i<n)
	{
		if(addr[i].ip_hash==addr[j].ip_hash)
			j++;
		else
		{
			printf("address=/");
			for(k=i;k<j;k++) printf("%s/",addr[k].ad);
			printf("%d.%d.%d.%d\n",addr[i].ip[0],addr[i].ip[1],addr[i].ip[2],addr[i].ip[3]);
			i=j;
		}
	}
	
	fclose(stdin );
	fclose(stdout);
	return 0;
}
