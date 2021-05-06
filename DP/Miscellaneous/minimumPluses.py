""" Question:
        Given a string as an equation i.e. 111=3,
        you need to find the minimum number of pluses
        that are to be placed in between the numbers
        in the LHS such that LHS becomes equal to RHS
        i.e. 1+1+1=3, thus the answer is 2. If no possible
        solution then return -1 as the answer.
        Another example:
            test case1: 30302430=60
            output: 3
            explanation: 3+3+24+30
            test case2: 30302420=60
            output: -1
"""

# Partially correct solution

import sys
import time

def recursion(q,a,i,j):
    if(i>=j): return 0,""
    else:
        ans = sys.maxsize
        ltr = ""
        for k in range(i,j):
            s1,s2 = q[i:k+1],q[k+1:j+1]
            i1,i2 = int(s1),int(s2)
            aa = int(a)
            temp = 0
            tstr = ""
            if(i1<=aa and i2<=aa):
                if(i1+i2==aa):
                    return 1,str(i1)+'+'+str(i2)
                else: continue
            elif(i1>aa and i2>aa):
                continue
            else:
                if(i1>=aa):
                    nop,gstr = recursion(q,str(aa-i2),0,k)
                    if(nop==sys.maxsize): continue
                    temp += 1+nop
                    tstr = gstr+'+'+str(i2)
                elif(i2>=aa):
                    nop,gstr = recursion(q,str(aa-i1),k+1,j)
                    if(nop==sys.maxsize): continue
                    temp += 1+nop
                    tstr = str(i1)+'+'+gstr
            if(temp<ans):
                ans = temp
                ltr = tstr
        return ans,ltr

memo = {}

def memoization(q,a,i,j):
    key = a+str(i)+str(j)
    if key in memo:
        return memo[key]
    if(i>=j): return 0,""
    else:
        ans = sys.maxsize
        ltr = ""
        for k in range(i,j):
            s1,s2 = q[i:k+1],q[k+1:j+1]
            i1,i2 = int(s1),int(s2)
            aa = int(a)
            temp = 0
            tstr = ""
            if(i1<=aa and i2<=aa):
                if(i1+i2==aa):
                    if(i2==0):
                        memo[key] = (0,str(i1))
                        return memo[key]
                    else:
                        memo[key] = (1,str(i1)+'+'+str(i2))
                        return memo[key]
                else: continue
            elif(i1>aa and i2>aa):
                continue
            else:
                if(i1>=aa):
                    nop,gstr = memoization(q,str(aa-i2),0,k)
                    if(nop==sys.maxsize): continue
                    if(i2==0):
                        temp += nop
                        tstr = gstr
                    else:
                        temp += 1+nop
                        tstr = gstr+'+'+str(i2) 
                elif(i2>=aa):
                    nop,gstr = memoization(q,str(aa-i1),k+1,j)
                    if(nop==sys.maxsize): continue
                    if(i1==0):
                        temp += nop
                        tstr = gstr
                    else:
                        temp += 1+nop
                        tstr = str(i1)+'+'+gstr
            if(temp<ans):
                ans = temp
                ltr = tstr
        memo[key] = (ans,ltr)
        return memo[key]

def minimum_pluses(A):
    # Write your code here
    q,a = A.split('=')
    #ans,lsa = recursion(q,a,0,len(q)-1)
    ans,lsa = memoization(q,a,0,len(q)-1)
    ans = ans if ans!=sys.maxsize else -1
    if ans!=-1: print(lsa)
    return ans

def main():
    start = time.time()
    A = input()
    result = minimum_pluses(A);
    print(result)
    print('Time taken:',time.time()-start)
if __name__ == "__main__":
    main()
