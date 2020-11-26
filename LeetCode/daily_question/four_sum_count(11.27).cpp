// 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l),
// 使得 A[i] + B[j] + C[k] + D[l] = 0。
// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。
// 所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
// https://leetcode-cn.com/problems/4sum-ii/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> mp;
    int count = 0;
    for(int i : A) {
        for(int j : B) {
            mp[i + j]++;
        }
    }
    for(int i : C) {
        for(int j : D) {
            if(mp[-(i + j)]) {
                count += mp[-(i + j)];  // 注意
            }
        }
    }
    return count;
}

int main()
{
    vector<int> a = {-1, -1};
    vector<int> b = {-1, 1};
    vector<int> c = {-1, 1};
    vector<int> d = {1, -1};
    cout << fourSumCount(a, b, c, d) << endl;
    return 0;
}