package codr7.snackis;

import codr7.jappkit.Repl;
import codr7.jappkit.db.Tx;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.time.Instant;

public class Main {
    public static void main(String[] args) {
        System.out.printf("Welcome to Snackis v0.1\n");

        var db = new DB(Path.of("db"));
        db.drop();
        db.open(Instant.now());

        var tx = new Tx();
        var me = new Profile(db);
        me.name = "Andreas Nilsson";
        var k = Profile.generateKey();
        me.setKey(k.getPublic());
        me.store(tx);
        tx.commit();

        System.out.printf("%s\n%s\n", me.name, Profile.encodeKey(me.key()));

        new Repl() {
            @Override
            protected String readLine(BufferedReader in, PrintStream out) throws IOException {
                out.print("snacki$ ");
                return super.readLine(in, out);
            }

            @Override
            protected void processLine(String in, PrintStream out) {
                var cmd = in.split("\\s+");

                if (cmd[0].equals("c")) {
                    out.println("Connect!");
                }
            }
        }.run(new BufferedReader(new InputStreamReader(System.in, StandardCharsets.UTF_8)), System.out);
    }
}
