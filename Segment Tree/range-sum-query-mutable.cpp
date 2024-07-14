class SegmentTree{
    vector<int>seg;
    public:
     SegmentTree(int n){
        seg.resize(4*n+1);
     }
     void build(int id, int l, int r, vector<int>&arr){
        if(l==r){
            seg[id] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        build(2*id+1, l, mid, arr);
        build(2*id+2, mid+1,r,arr);
        seg[id]=seg[2*id+1] + seg[2*id+2];
     }
     int query(int id, int l, int r, int ql, int qr){
        if(ql>r || qr<l) return 0;
        if(ql<=l && qr>=r) return seg[id];
        int mid=(l+r)>>1;
        int left = query(2*id+1,l,mid,ql,qr);
        int right =query(2*id+2,mid+1,r,ql,qr);
        return left+right;
     }
     void update(int id, int l, int r, int i, int val){
        if(l==r){
            seg[id]=val;
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) update(2*id+1,l,mid,i,val);
        else update(2*id+2,mid+1,r,i,val);
        seg[id]=seg[2*id+1]+seg[2*id+2];
     }
};
class NumArray {
public:
    SegmentTree sg;
    int n;
    NumArray(vector<int>& nums): sg(nums.size()), n(nums.size()) {
       sg.build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        sg.update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sg.query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */