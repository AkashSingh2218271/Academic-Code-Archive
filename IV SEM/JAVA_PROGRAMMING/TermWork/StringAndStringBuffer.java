public class StringAndStringBuffer {
        public static void main(String[] args) {
            String str = "Graphic Era Hill University";
            StringBuffer strBuffer = new StringBuffer(str);
    
            // String methods
            System.out.println("Original String: " + str);
            System.out.println("Length of String: " + str.length());
            System.out.println("Character at index 5: " + str.charAt(5));
            System.out.println("Substring from index 8 to 13: " + str.substring(8, 13));
            System.out.println("Index of 'Hill': " + str.indexOf("Hill"));
            System.out.println("Replace 'Hill' with 'University': " + str.replace("Hill", "University"));
            System.out.println("Uppercase: " + str.toUpperCase());
            System.out.println("Lowercase: " + str.toLowerCase());
            System.out.println("Trim: " + str.trim());
            System.out.println("Starts with 'Graphic': " + str.startsWith("Graphic"));
            System.out.println("Ends with 'University': " + str.endsWith("University"));
            System.out.println("Contains 'Era': " + str.contains("Era"));
            System.out.println("Splitting by space: ");
            String[] splitArray = str.split("\\s");
            for (String word : splitArray) {
                System.out.println(word);
            }
            System.out.println();
    
            // StringBuffer methods
            System.out.println("Original StringBuffer: " + strBuffer);
            strBuffer.append(" Dehradun");
            System.out.println("After appending ' Dehradun': " + strBuffer);
            strBuffer.insert(16, " in");
            System.out.println("After inserting ' in' at index 16: " + strBuffer);
            strBuffer.delete(23, 33);
            System.out.println("After deleting ' Hill University': " + strBuffer);
            strBuffer.reverse();
            System.out.println("After reversing: " + strBuffer);
            System.out.println("Capacity of StringBuffer: " + strBuffer.capacity());
            System.out.println("Character at index 5: " + strBuffer.charAt(5));
            System.out.println("Length of StringBuffer: " + strBuffer.length());
            System.out.println("Code point at index 5: " + strBuffer.codePointAt(5));
            System.out.println("Code point count between index 0 and 10: " + strBuffer.codePointCount(0, 10));
            strBuffer.deleteCharAt(0);
            System.out.println("After deleting char at index 0: " + strBuffer);
            strBuffer.ensureCapacity(50);
            System.out.println("Ensuring capacity to 50: " + strBuffer);
            char[] dst = new char[strBuffer.length()];
            strBuffer.getChars(0, strBuffer.length(), dst, 0);
            System.out.print("Getting characters: ");
            for (char c : dst) {
                System.out.print(c);
            }
            System.out.println();
            System.out.println("Index of 'Hill': " + strBuffer.indexOf("Hill"));
            System.out.println("Last index of 'i': " + strBuffer.lastIndexOf("i"));
            strBuffer.replace(0, 7, "University");
            System.out.println("After replacing 'Graphic Era' with 'University': " + strBuffer);
            strBuffer.setCharAt(0, 'U');
            System.out.println("After setting char at index 0 to 'U': " + strBuffer);
            System.out.println("Substring from index 5 to 10: " + strBuffer.substring(5, 10));
            String strFromBuffer = strBuffer.toString();
            System.out.println("Converted to String: " + strFromBuffer);
            strBuffer.trimToSize();
            System.out.println("Trimming size: " + strBuffer);
        }
}
