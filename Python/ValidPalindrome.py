class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(ch.lower() for ch in s if ch.isalnum())
        for i in range(0,int(len(s)/2)):
            if s[i]!=s[len(s)-i-1]: return False
        return True;