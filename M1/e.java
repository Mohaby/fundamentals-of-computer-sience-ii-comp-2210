 @Override
   public boolean equals(Set<T> s) {

   
    
    if (this.size() != s.size()) return false;
    Iterator<T> iter = this.iterator();
    while (iter.hasNext()) {
        if (!s.contains(iter.next())) return false;
    }
    return true;
}

 public static int length(Node n) {
        Node current = n;
            int length = 0;
        while(current != null) {
            length ++;
            current = current.next;
        }
        return length;
    
    }
    
    
    
    public T max() {
    if (front == null) {
    return null;
    }
    Node temp = front.next;
    T max = front.element; 
    while (temp != null) { 
    T val = temp.element;
    if(val.compareTo(max) > 0) {
    max = val;
    }
    temp = temp.next;
    }
    return max;
    }
    
    
    int len = array.length;   // length of the given array
        Object last = array[len-1]; // to store the last element
        for (int i = len-1; i >index; i--) {    // right shift elements of the array till the given index
            array[i] = array[i-1];  // replace previous one with current element
        }
        array[index] = last;    // at last place the last element at the given position
    }

}


int size = 1; 
Node head = n;
Node CurrentNode = head;
while(CurrentNode.next !=null)
{
CurrentNode = CurrentNode.next;
}
return size;
}

