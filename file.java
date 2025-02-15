public long[]countKConstraintSubstrings(String s,int k,int[]queries){
int n=s.length();
int[]LtoR =new int[n],[]RtoL=new int[n],
int zero=0,one=0,j=0;
for(int i=0;i<n;i++){
if(s.charAt(i)=='0')
zero++;
else
one++;
while(j<n&&(zero>k&&one>k)){
s.charAt(j)=='0')
zero--;
else
one--;
j++;
}
RtoL[i]=j;
}
zero=0,one=0,j=n-1;
for(int i=n-1;i>=0;i--){
if(s.charAt(i)=='0')
zero++;
else
one++;
while(j<n&&(zero>k&&one>k)){
if(s.charAt(j)=='0')
zero--;
else
one--;
j--;
LtoR[i]=j;
}
long[]prefix=new long[queries.length];
int g=0;
for(int[]q:queries){
int l=q[0],r=q[1];
int mid=Math.min(LtoR[l],r);
long cnt=mid-l+1;
long ans1=cnt*(cnt+1)/2;
if(mid<r){
ans1+=prefix[r]-prefix[mid];
}
ans[g++]=ans1;
}
return ans;
}