import static org.junit.jupiter.api.Assertions.*;

class MainTest {
    @org.junit.jupiter.api.BeforeEach
    void setUp() {

    }

    @org.junit.jupiter.api.AfterEach
    void tearDown() {
    }

    @org.junit.jupiter.api.Test
    void isValid() {
        boolean valid = Main.isValid("><");
        assertFalse(valid);
    }

    @org.junit.jupiter.api.Test
    void isValid2() {
        boolean valid = Main.isValid("<]");
        assertFalse(valid);
    }

    @org.junit.jupiter.api.Test
    void isValid3() {
        boolean valid = Main.isValid("())");
        assertFalse(valid);
    }

    @org.junit.jupiter.api.Test
    void isValid4() {
        boolean valid = Main.isValid("(<{}>)");
        assertTrue(valid);
    }

    @org.junit.jupiter.api.Test
    void isValid5() {
        boolean valid = Main.isValid("()<>{}[]{}");
        assertTrue(valid);
    }

    @org.junit.jupiter.api.Test
    void isValid6() {
        boolean valid = Main.isValid("(){}}{");
        assertFalse(valid);
    }

}