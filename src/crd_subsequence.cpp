// 代码随想录-动态规划-子序列相关题
// 2024-06-25
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ----------编辑距离----------

// 392.判断子序列
// 拿到题后想了一下，用动态规划解出来了
// 其实脑袋里面第一想法是用map，但是子序列相对顺序要保持，用map只是单词相同，位置是无序的，所以不能用map
// 用例：s = "abc"， t = "ahbgdc"
// class Solution
// {
// public:
//     bool isSubsequence(string s, string t)
//     {
//         if (s.size() > t.size())
//             return false;
//         vector<vector<bool>> dp(s.size() + 1, vector<bool>(t.size() + 1, false));
//         for (int j = 0; j <= t.size(); j++)
//             dp[0][j] = true;
//         for (int i = 1; i <= s.size(); i++)
//         {
//             for (int j = 1; j <= t.size(); j++)
//             {
//                 if (s[i - 1] == t[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1];
//                 else
//                 {
//                     dp[i][j] = dp[i][j - 1];
//                 }
//             }
//         }
//         return dp[s.size()][t.size()];
//     }
// };
// gia！这题用双指针无敌简单，我说这分类咋是个简单题呢
// bool isSubsequence(string s, string t)
// {
//     int l = 0, r = 0;
//     while (l < s.size() && r < t.size())
//     {
//         if (s[l] == t[r])
//         {
//             l++;
//             r++;
//         }
//         else
//         {
//             r++;
//         }
//     }
//     return l == s.size();
// }

// 115.不同的子序列
// 真难，真的，理解动规数组定义理解半天；理解状态转移方程又理解了半天，这个题不复习的话下次遇到必然还是做不出来
// int numDistinct(string s, string t)
// {
//     vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
//     for (int i = 0; i <= s.size(); i++)
//         dp[i][0] = 1;
//     for (int i = 1; i <= s.size(); i++)
//     {
//         for (int j = 1; j <= t.size(); j++)
//         {
//             if (s[i - 1] == t[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//             else
//                 dp[i][j] = dp[i - 1][j];
//         }
//     }
//     return dp[s.size()][t.size()];
// }

// 583.两个字符串的删除操作
// 和编辑距离的思路一样
// int minDistance(string word1, string word2)
// {
//     vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
//     for (int j = 0; j <= word2.size(); j++)
//         dp[0][j] = j;
//     for (int i = 0; i <= word1.size(); i++)
//         dp[i][0] = i;
//     for (int i = 1; i <= word1.size(); i++)
//     {
//         for (int j = 1; j <= word2.size(); j++)
//         {
//             if (word1[i - 1] == word2[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1];
//             else
//                 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
//         }
//     }
//     return dp[word1.size()][word2.size()];
// }

// 72.编辑距离
// 这个真的挺难想明白的，特别是状态转移方程
// 想出动规解法的人真素天才！
// int minDistance(string word1, string word2)
// {
//     int m = word1.size();
//     int n = word2.size();
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//     for (int j = 0; j <= n; j++)
//         dp[0][j] = j;
//     for (int i = 0; i <= m; i++)
//         dp[i][0] = i;
//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (word1[i - 1] == word2[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1];
//             else
//                 dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
//         }
//     }
//     return dp[m][n];
// }

// ----------回文----------

// 647.回文子串
// 这个题经典，记住mycount函数的参数和里面while循环的写法
// 还有主函数里面为什么两次调用
// int myCount(const string &s, int l, int r)
// {
//     int n = s.size();
//     int count = 0;
//     while (l >= 0 && r < n && s[l] == s[r])
//     {
//         count++;
//         l--;
//         r++;
//     }
//     return count;
// }
// int countSubstrings(string s)
// {
//     int ans = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         ans += myCount(s, i, i);
//         ans += myCount(s, i, i + 1);
//     }
//     return ans;
// }

// 这个题用动规更简单
// int countSubstrings(string s)
// {
//     vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
//     int ans = 0;
//     for (int i = s.size() - 1; i >= 0; i--)
//     {
//         for (int j = i; j < s.size(); j++)
//         {
//             if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
//             {
//                 dp[i][j] = true;
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

// 5.最长回文子串
// 先想到的和上面题一样的思路
// int maxlen = 0;
// int start = 0;
// void myCount(const string &s, int l, int r)
// {
//     int n = s.size();
//     while (l >= 0 && r < n && s[l] == s[r])
//     {
//         if (maxlen < r - l + 1)
//         {
//             maxlen = r - l + 1;
//             start = l;
//         }
//         l--;
//         r++;
//     }
// }
// string longestPalindrome(string s)
// {
//     for (int i = 0; i < s.size(); i++)
//     {
//         myCount(s, i, i);
//         myCount(s, i, i + 1);
//     }
//     return s.substr(start, maxlen);
// }

// 用动规做了一下，感觉这题用动规更好理解
// string longestPalindrome(string s)
// {
//     vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
//     int start = 0;
//     int maxlen = 0;
//     for (int i = s.size() - 1; i >= 0; i--)
//     {
//         for (int j = i; j < s.size(); j++)
//         {
//             if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
//             {
//                 dp[i][j] = true;
//                 if (maxlen < j - i + 1)
//                 {
//                     maxlen = j - i + 1;
//                     start = i;
//                 }
//             }
//         }
//     }
//     return s.substr(start, maxlen);
// }