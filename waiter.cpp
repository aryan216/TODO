bool isPrime(int n){
   
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return false;
    }   
    return true;
}
vector<int> waiter(vector<int> number, int q) {
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    int count=0;
    int m=number.size();
    for(int i = 1; count<q; i++)
    {
       
        if(isPrime(i))
        {
            c.push_back(i);
            count++;
        }
    }
    int n=c.size();
    for(int i=0;i<n;i++)
    {
        for(int j=number.size()-1;j>=0;j--)
        {
            if(number[j]%c[i]==0)
            {
                b.push_back(number[j]);
                      
            }
            else
            {   
                a.push_back(number[j]);
            }
        }
        number.clear();
        for(int t=0;t<b.size();t++)
        {
            d.push_back(b[b.size()-t-1]);
                
        }
        for(int k=0;k<a.size();k++)
        {
                
            if(i>=n-1)
            {
                d.push_back(a[a.size()-k-1]);
            }
        }
        number=a;
        a.clear();
        b.clear();   
    }
    return d;   
}
