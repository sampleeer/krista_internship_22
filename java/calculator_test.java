import org.junit.jupiter.api.Test;
import ru.ac.uniyar.mf.summer.Main;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class calculator_test {
        @Test
        void addition(){
                String actual = Main.calculate("1", "+", "1");
                assertEquals( "2", actual);

        }

        @Test
        void multiplication(){
                String actual = Main.calculate("1", "*", "1");
                assertEquals( "1", actual);

        }
        @Test
        void divide(){
                String actual = Main.calculate("8", "/", "2");
                assertEquals( "4", actual);

        }

        @Test
        void minus(){
                String actual = Main.calculate("1", "-", "1");
                assertEquals( "0", actual);

        }
        @Test
        void zeero_exception(){
                String actual = Main.calculate("1", "/", "0");
                assertEquals( "1", actual);

        }


}
