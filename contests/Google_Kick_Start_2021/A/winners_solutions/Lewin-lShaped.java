import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Solution {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        LShapedPlots solver = new LShapedPlots();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class LShapedPlots {
        int[][][] pg;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int r = in.nextInt(), c = in.nextInt();
            int[][] grid = new int[r][c];
            for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) grid[i][j] = in.nextInt();
            pg = new int[4][r][c];
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == 0) pg[0][i][j] = pg[1][i][j] = 0;
                    else {
                        pg[0][i][j] = 1 + (i > 0 ? pg[0][i - 1][j] : 0);
                        pg[1][i][j] = 1 + (j > 0 ? pg[1][i][j - 1] : 0);
                    }
                }
            for (int i = r - 1; i >= 0; i--)
                for (int j = c - 1; j >= 0; j--) {
                    if (grid[i][j] == 0) pg[2][i][j] = pg[3][i][j] = 0;
                    else {
                        pg[2][i][j] = 1 + (i + 1 < r ? pg[2][i + 1][j] : 0);
                        pg[3][i][j] = 1 + (j + 1 < c ? pg[3][i][j + 1] : 0);
                    }
                }
            int res = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == 0) continue;
                    for (int di = 0; di < 4; di++) {
                        for (int dc = -1; dc <= 1; dc += 2) {
                            int dj = (di + dc + 4) % 4;
                            int l1 = pg[di][i][j], l2 = pg[dj][i][j];
                            res += Math.max(0, Math.min(l1 / 2, l2) - 1);
                        }
                    }
                }
            }
            out.printf("Case #%d: %d\n", testNumber, res);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new UnknownError();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}

