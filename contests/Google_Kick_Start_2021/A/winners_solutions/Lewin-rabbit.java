import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        RabbitHouse solver = new RabbitHouse();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class RabbitHouse {
        public int[] dx = new int[]{-1, 0, 1, 0};
        public int[] dy = new int[]{0, -1, 0, 1};

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int r = in.nextInt(), c = in.nextInt();
            int[][] grid = new int[r][c];
            for (int i = 0; i < r; i++) grid[i] = in.readIntArray(c);
            PriorityQueue<RabbitHouse.Item> pq = new PriorityQueue<>(Comparator.comparingInt(x -> -x.val));
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++) {
                    pq.add(new RabbitHouse.Item(i, j, grid[i][j]));
                }
            long res = 0;
            while (pq.size() > 0) {
                RabbitHouse.Item it = pq.poll();
                if (grid[it.r][it.c] != it.val) continue;
                for (int k = 0; k < 4; k++) {
                    int nx = it.r + dx[k], ny = it.c + dy[k];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] < grid[it.r][it.c] - 1) {
                        res += grid[it.r][it.c] - 1 - grid[nx][ny];
                        grid[nx][ny] = grid[it.r][it.c] - 1;
                        pq.add(new RabbitHouse.Item(nx, ny, grid[nx][ny]));
                    }
                }
            }
            out.printf("Case #%d: %d\n", testNumber, res);
        }

        static class Item {
            public int r;
            public int c;
            public int val;

            public Item(int r, int c, int val) {
                this.r = r;
                this.c = c;
                this.val = val;
            }

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

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
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

