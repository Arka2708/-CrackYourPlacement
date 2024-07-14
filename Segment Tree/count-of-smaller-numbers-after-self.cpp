#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> seg;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        seg.resize(4*n+1);
    }

    void build(int id,int l,int r) {
        if(l==r){
            seg[id] = 0;
            return;
        }
        int mid = (l + r)>>1;
        build(2*id + 1, l, mid);
        build(2*id + 2, mid + 1, r);
        seg[id] = seg[2*id+1]+seg[2*id+2];
    }

    void update(int id,int l,int r,int pos) {
        if(l==r) {
            seg[id]++;
            return;
        }
        int mid = (l + r)>>1;
        if(pos<= mid) update(2*id + 1, l, mid, pos);
        else update(2*id + 2, mid + 1, r, pos);
        seg[id] = seg[2*id + 1] + seg[2*id + 2];
    }

    int query(int id, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && qr >= r) return seg[id];
        int mid = (l + r)>>1;
        int left = query(2 * id + 1, l, mid, ql, qr);
        int right = query(2 * id + 2, mid + 1, r, ql, qr);
        return left + right;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int offset = 1e4;
        SegmentTree sg(2 * offset + 1);
        sg.build(0, 0, 2 * offset);
        vector<int> ans(n);

        for (int i = n-1; i>=0; --i) {
            int num = nums[i];
            num +=offset;
            ans[i] = sg.query(0,0,2*offset,0,num - 1);
            sg.update(0, 0, 2*offset, num);
        }
        return ans;
    }
};


