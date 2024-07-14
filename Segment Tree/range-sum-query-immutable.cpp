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
};
class NumArray {
public:
    SegmentTree sg;
    int n;
    NumArray(vector<int>& nums): sg(nums.size()), n(nums.size()) {
       sg.build(0,0,n-1,nums);
    }
    
    int sumRange(int left, int right) {
        return sg.query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */