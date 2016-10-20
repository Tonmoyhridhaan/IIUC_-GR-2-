#define mx 100009
long long arr[mx];
long long tree[mx*3];
long long lazy[mx*3];

void build(long long node,long long b,long long e)
{
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    long long mid=(b+e)/2;
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update(long long node,long long b,long long e,long long l,long long r,long long val)
{
    if(lazy[node]!=0){
        tree[node]+=(e-b+1)*lazy[node];
        if(b!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(b>e || b>r || e<l){
        return;
    }
    if(b>=l && e<=r){
        tree[node]+=(e-b+1)*val;
        if(b!=e){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    long long mid=(b+e)/2;
    update(node*2,b,mid,l,r,val);
    update(node*2+1,mid+1,e,l,r,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(long long node,long long b,long long e,long long l,long long r)
{
    if(b>e || b>r || e<l){
        return 0;
    }
    if(lazy[node]!=0){
        tree[node]+=(e-b+1)*lazy[node];
        if(b!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(b>=l && e<=r){
        return tree[node];
    }
    long long mid=(b+e)/2;
    long long p1=query(node*2,b,mid,l,r);
    long long p2=query(node*2+1,mid+1,e,l,r);
    return (p1+p2);
}
