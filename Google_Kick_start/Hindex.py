def main():
    t=int(input())
    p=1
    while(p<=t):
        n=int(input())
        ls=list(map(int,input().split()))
        ans=[]
        dic={}
        ch=1
        for i in range(len(ls)):
            if(i==0):
                ans.append(1)
                ch=1
            else:
                k=ls[i]
                cnt=1
                while(k>ch):
                    for ky in dic:
                        if(ky>=k):
                            cnt+=dic[ky]
                    if(cnt>=k):
                        break
                    k-=1
                    cnt=1
                ch=max(ch,k)
                ans.append(k)
            dic[ls[i]]=dic.get(ls[i],0)
            dic[ls[i]]+=1
            
            
        
        print('Case #%d:' % (p),end=' ')
        for i in range(len(ans)):
            print(ans[i],end=' ')
        p+=1
        
        
main()
