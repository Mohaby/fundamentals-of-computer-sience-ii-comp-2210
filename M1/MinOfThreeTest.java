import org.junit.Assert;
import static org.junit.Assert.*;
//import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class MinOfThreeTest {


   


   /** A test that test Min1 **/
   @Test public void testMin1() {
      Assert.assertEquals(1,MinOfThree.min1(3, 1,2));
      

   }
    

   
    /** A test that test Min2. **/
   @Test public void testMin2() {
      Assert.assertEquals(1,MinOfThree.min2(3, 1,2));



   
}
}