import static java.lang.System.out;
import java.lang.StringBuffer;

class PermutationsApp {
    static void permuteStrings(String prefix, String buf) {
        if(buf.length() == 2) {
            // Stopping condition
            out.println(prefix + buf.charAt(0) + buf.charAt(1));
            out.println(prefix + buf.charAt(1) + buf.charAt(0));
            }
        else {
            for(int i=0; i < buf.length(); i++) {
                String newPrefix = prefix +buf.charAt(i);
                String leftovers;
                if(i == 0)
                    leftovers = buf.substring(i+1,buf.length());
                else
                    leftovers = buf.substring(0,i) + buf.substring(i+1,buf.length());
                permuteStrings(newPrefix, leftovers);
                }
            }
        }

    static void permuteStrings2(String prefix, String buf) {
        if(buf.length() == 2) {
            // Stopping condition
            out.println(prefix + buf.charAt(0) + buf.charAt(1));
            out.println(prefix + buf.charAt(1) + buf.charAt(0));
            }
        else {
            for(int i=0; i < buf.length(); i++) {
                String newPrefix = prefix +buf.charAt(i);
                StringBuffer leftovers = new StringBuffer(buf.length());
                for(int x=0;x<buf.length();x++) {
                    if(x != i)
                        leftovers.append(buf.charAt(x));
                    }
                permuteStrings(newPrefix, leftovers.toString());
                }
            }
        }


    public static void main(String[] args) {
        if(args.length == 1 && args[0].length() >= 2) {
            // permuteStrings("", args[0]);
            permuteStrings2("", args[0]);
            }
        else
            out.println("Provide one and only one argument that is longer than 2 characters");
    }
}

