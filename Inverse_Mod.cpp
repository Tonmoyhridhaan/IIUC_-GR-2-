ll mod(ll b,ll p){
    if(p==1) return b;
    if(p%2==1) return(mod(b,p-1)*b)%1000003;
    ll res=mod(b,p/2);
    return (res*res)%1000003;
}
