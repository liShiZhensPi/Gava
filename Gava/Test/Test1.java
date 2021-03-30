package Test;

import Test.Add;

public class Test1 {

    public static void main(String[] args){
        int[] a = {1,2,3,4,5,6};
        int[] b = {2,3,4,5,6,7};
        Add ob = new Add();
        int[] res = new int[6];
        Add adder = new Add();
        for(int i = 0;i<res.length;i++){
            res[i] = ob.add(a[i],b[i]);
        }
    }
}
