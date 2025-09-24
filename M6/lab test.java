public int depth(T value) {
   Node n = search(root, value);
   if (n == null)
return -1;
   int root_height = height(root);
   return (root_height - height(n)) + 1;
}
public Node search(Node n, T value) {
   if (n == null)
return null;
   if (n.element.compareTo(value) == 0)
      return n;
   Node left = search(n.left, value);
   if (left != null)
      return left;
   Node right = search(n.right, value);
   if (right != null)
      return right;
   return null;
}
       }
       
       
       /**
       * Returns the depth of the node containing value
       * or -1 if value not present.
       */
      public int depth(T value) {
         if (this.root == null)
            return -1;
         else {
            Node n = this.root;
            boolean found  = false;
            while((n!= null)  && (!found))
            {
               if (n.element.compareTo(value) == 0)
                  found  = true ;
               else  if (n.element.compareTo(value) > 0)
                  if (n.left != null)
                     n= n.left;
                  else
                     n = n.right;
               else
                  if (n.right != null)
                     n= n.right;
                  else
}
n = n.left;
                Node m = this.root;
                if (found){
                   int count = 1;
                   while (m != n) {
                      if (m.element.compareTo(n.element) > 0){
                         if (m.left != null)
m = m.left;
                         else
                            m = m.right;
}
else

if (m.right != null)
                            m = m.right;
                         else
                            m = m.left;
count++; }
                   return count;
                }
                else
                   return -1;
} }



      // Returns the smallest element in this binary search tree. If this tree is

      //empty, this method returns null

  public T min() {

            

            return min(root);

      }

     

      private T min(Node node) {

           

            if (node == null) {

              

                  return null;

            }

            

            if (node.left != null) {

                  return min(node.left);

            }

          

            return node.element;

      }

