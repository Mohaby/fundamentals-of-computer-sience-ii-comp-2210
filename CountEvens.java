/**
 * Count the number of even values in a chain of linked nodes.
 *
 */
public class CountEvens {

    //  C O M P L E T E   T H I S    M E T H O D 

    /**
     * Returns the number of even values in the paramter.
     */
    public int countEvens(Node firstNode) {

    
    
    

			//even count
			int even = 0;
			
			//assign firstNode to curr
			Node curr = firstNode;
			
			//Loop until the end
			while( curr != null) {
				//if even number
				if(curr.value%2 ==0)
					++even;
				
				//increment curr to next element
				curr = curr.next;
			}
			
			//return even
			return even;
		}

    class Node {
        int value;
        Node prev;
        Node next;

        public Node(int val) {
            value = val;
            prev = null;
            next = null;
        }
    }

}
