import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;

/**
 * Return the elements in a collection that are strictly less than a specified
 * value.
 *
 */
public class LessThanSubset {

    // C O M P L E T E   T H I S   M E T H O D 

    /**
     * Returns the elements in collection strictly less than value.
     */
    public static <T extends Comparable<T>> 
            Collection<T> lessThanSubset(Collection<T> collection, T value) {
        Collection<T> result = new ArrayList< T >();
        
         for(int i=0; i<collection.size(); i++)
    {
      if(value.compareTo(collection.get(i)))
        result.add(value);
    }
    return result;
  }

}