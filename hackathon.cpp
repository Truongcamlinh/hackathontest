#include <stdio.h>
int n;

int main()
{
    int a[100];
    int option;
    while(option!=15)
    {
        printf("\n\t\tMENU\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu.\n");
        printf("2. In mang (arr[0]=..., arr[1]=...)\n");
        printf("3. Dem so luong so hoan hao.\n");
        printf("4. Dem so luong so nguyen to.\n");
        printf("5. Tim gia tri lon thu 2 (khong sap xep).\n");
        printf("6. Tim gia tri nho thu 2 (khong sap xep).\n");
        printf("7. Them phan tu tai vi tri.\n");
        printf("8. Xoa phan tu tai vi tri.\n");
        printf("9. Sap xep mang tang dan (sap xep chen).\n");
        printf("10. Sap xep mang giam dan (sap xep chen).\n");
        printf("11. Tim kiem phan tu (Tim kiem nhi phan).\n ");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat.\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau.\n");
        printf("14. Dao nguoc mang.\n");
        printf("15. Thoat.\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            printf("Nhap kich thuoc cua mang: ");
            scanf("%d", &n);

            for (int i = 0; i < n; ++i)
            {
                printf("Nhap phan tu thu %d: ", i + 1);
                scanf("%d", &a[i]);
            }
        }
        break;
        case 2:
        {
            printf("Cac phan tu trong mang: \n");
            for (int i = 0; i < n; ++i)
            {
                printf("arr[%d] = %d\n", i, a[i]);
            }
        }
        break;
        case 3:
        {
            int count = 0;
            for (int i = 0; i < n; ++i)
            {
                int sum = 1;
                for (int j = 2; j * j <= a[i]; ++j)
                {
                    if (a[i] % j == 0)
                    {
                        sum += j;
                        if (!(a[i] / j == j))
                            sum += a[i] / j;
                    }
                }
                if (sum == a[i] && a[i]>=6)
                    {
						count++;
						printf("%d ",a[i]);
					}
            }
            printf("So luong so hoan hao: %d", count);
        }
        break;
        
        case 4:
        {
        	int count=0;
        	for(int i=0;i<n;++i)
        	{
        		int prime=0;
        		for(int j=2;j*j<=a[i];++j)
        		{
        			if (a[i]%j==0)
        			{
        				prime =1;
        				break;
					}
				}
				if(!prime && a[i]>=2)
				{
					++count;
				}
			}
			printf("So luong cac phan tu la so nguyen to trong mang: %d", count);
        }
        break;
        case 5:
        {
        	int max=a[0], max2;
        	for(int i=1;i<n;++i)
        	{
        		if(a[i]>max)
        		{
        			max2=max;
        			max=a[i];
				}
				else if (a[i] > max2 && a[i] != max)  
					max2 = a[i];
			}
			printf("Phan tu lon thu hai trong mang: %d", max2);
        }
        break;
		case 6:
		{
		    int min = a[0], min2;
		    min2 = (a[0] < a[1]) ? a[1] : a[0];
		
		    for(int i = 1; i < n; ++i)
		    {
		        if(a[i] < min)
		        {
		            min2 = min;  
		            min = a[i]; 
		        }
		        else if(a[i] < min2 && a[i] != min)
		        {
		            min2 = a[i];
		        }
		    }
		    
		    printf("Phan tu nho thu hai trong mang: %d", min2);
		}
		break;
        case 7:
        {
        	int value, idx;
        	printf("Nhap gia tri can them: ");
        	scanf("%d", &value);
        	printf("Nhap vi tri can them: ");
        	scanf("%d", &idx);
        	
        	if(idx>n)
        	{
        		a[idx-1]=value;
				n = idx;	
			}
			else
        	{
				for(int i=n;i>=idx;--i)
        		{
        			a[i]=a[i-1];
				}	
				a[idx-1]=value;
				n++;
			}
        }
        break;
        case 8:
        {
        	int idx;
        	printf("Nhap vi tri can xoa: ");
        	scanf("%d", &idx);
        	
        	for(int i=idx-1;i<n-1;++i)
        	{
        		a[i]=a[i+1];
			}
			--n;
        }
        break;
        case 9:
        {
        	for(int i=1;i<n;++i)
        	{
        		int tmp=a[i], j=i-1;
        		while(j>=0 && a[j]>tmp)
        		{
					a[j+1]=a[j];
					--j;
				}
				a[j+1]=tmp;
			}
        }
        break;
        case 10:
        {
        	for(int i=1;i<n;++i)
        	{
        		int tmp=a[i], j=i-1;
        		while(j>=0 && a[j]<tmp)
        		{
					a[j+1]=a[j];
					--j;
				}
				a[j+1]=tmp;
			}
        }
        break;
        case 11:
        {
            int value;
            printf("Nhap phan tu can tim: ");
            scanf("%d", &value);

            int found = 0;
            int l = 0, r = n - 1;
            while (l <= r)
            {
                int m = (l + r);
                if (a[m] == value)
                {
                    printf("Gia tri %d ton tai trong mang.\n", value);
                    found = 1;
                    break;
                }
                else if (a[m] < value)
                    l = m + 1;
                else
                    r = m - 1;
            }
            if (!found)
                printf("Gia tri %d khong ton tai trong mang.\n", value);
            break;
        }
        case 12:
        {
           int newS=n;
		   for(int i=0;i<newS; ++i)
		   {
		   	for(int j=i+1; j<newS;++j )
		   	{
		   		if(a[i]==a[j])
				{
				  	for(int k=j;k<newS-1;++k)
				  	{
				  		a[k]=a[k+1];
					}
					newS--;
					j--;
				} 
			   }
			} 
			n=newS;
            break;  
        }
        case 13:
        {
        	int odd[n], even[n];
			
			int j=0,k=0;
			for(int i=0;i<n;++i)
			{
				if(a[i]%2==0)
				{
					even[j++]=a[i];
				}
				else
					odd[k++]=a[i];
			}
			
			for(int i=1;i<j;++i)
        	{
        		int tmp=even[i], p=i-1;
        		while(p>=0 && even[p]>tmp)
        		{
					even[p+1]=even[p];
					--p;
				}
				even[p+1]=tmp;
			}
			
			for(int i=1;i<k;++i)
        	{
        		int tmp=odd[i], p=i-1;
        		while(p>=0 && odd[p]>tmp)
        		{
					odd[p+1]=odd[p];
					--p;
				}
				odd[p+1]=tmp;
			}
			
			for(int i=0;i<j;++i)
			{
				a[i]=even[i];
			}
			for(int i=0;i<k;++i)
			{
				a[j+i]=odd[i];
			}
        }
        break;
        case 14:
        {
        	for(int i=0;i<n/2;++i)
			{
				int tmp=a[i];
				a[i]=a[n-i-1];
				a[n-i-1]=tmp;	
			} 
        }
        break;
        case 15:
		{
			printf("Tam biet.\n");
			return 0; 
		} 
        default:
			printf("Lua chon khong hop le. Nhap lai.\n");
			break; 
        }
    }
}

