import java.util.Arrays;


public final class Selector1 {

  
   public static int min(int[] a)
   {
       int min=a[0];
       for(int i=0;i<a.length;i++)
           if(min>a[i])
               min=a[i];
       return min;
   }
   public static int max(int[] a)
   {
       int maxi=a[0];
       for(int i=0;i<a.length;i++)
           if(maxi<a[i])
               maxi=a[i];
       return maxi;
   }
  
   public static int kmin(int[] a,int k)
   {
int n = a.length;
for (int i = 0; i < n-1; i++)
for (int j = 0; j < n-i-1; j++)
if (a[j] > a[j+1])
{
int temp = a[j];
a[j] = a[j+1];
a[j+1] = temp;
}
int[] temp = new int[n];
int j = 0;
for (int i=0; i<n-1; i++){
if (a[i] != a[i+1]){
temp[j++] = a[i];
}
}
return temp[k-1];
   }
  
   public static int kmax(int[] a,int k)
   {
int n = a.length;
for (int i = 0; i < n-1; i++)
for (int j = 0; j < n-i-1; j++)
if (a[j] < a[j+1])
{
int temp = a[j];
a[j] = a[j+1];
a[j+1] = temp;
}
int[] temp = new int[n];
int j = 0;
for (int i=0; i<n-1; i++){
if (a[i] != a[i+1]){
temp[j++] = a[i];
}
}
return temp[k-1];
   }
  
   public static int[] range(int[] a,int low,int high)
   {
       int count=0;
       for(int i=0;i<a.length;i++)
           if(low<=a[i] && a[i]<=high)
               count++;
       int ret[]=new int[count];
       int k=0;
       for(int i=0;i<a.length;i++)
           if(low<=a[i] && a[i]<=high)
               ret[k++]=a[i];
       return ret;
   }
  
   public static int floor(int[] a,int key)
   {
       int ret=min(a);
       for(int i=0;i<a.length;i++)
           if(a[i]<=key)
               if(ret<=a[i])
               ret=a[i];
       return ret;
   }
   public static int ceiling(int[] a,int key)
   {
       int ret=max(a);
       for(int i=0;i<a.length;i++)
           if(a[i]>=key && ret>=a[i])
               ret=a[i];
       return ret;
   }
  
   //public static void main(String[] args) {
       //int a[]={8,2,8,7,3,3,4};
       //System.out.println(min(a));
       //System.out.println(max(a));
       //System.out.println(range(a),3,7);
       //System.out.println(floor(a,5));
       //System.out.println(ceiling(a,5));
       //System.out.println(kmin(a,3));
       //System.out.println(kmax(a,3));
   //}
  
}

