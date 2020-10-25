package codr7.snackis;

import codr7.jappkit.db.Tx;

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
        me.initKey();
        me.store(tx);
        tx.commit();

        System.out.printf("%s\n%s\n", me.name, Profile.encodeKey(me.key()));
    }
}
