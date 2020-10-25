package codr7.snackis;

import codr7.jappkit.E;
import codr7.jappkit.db.Mod;
import codr7.jappkit.db.Rec;

import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.Key;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;

public class Profile extends Mod {
    public static final String KEY_ALGORITHM = "AES";
    public static final int KEY_SIZE = 256;

    public static Make<Profile> make(DB db) { return (rec) -> { return new Profile(db, rec); }; }

    public static String encodeKey(Key in) {
        var outBytes = new ByteArrayOutputStream();

        try {
            ObjectOutputStream out = new ObjectOutputStream(outBytes);
            out.writeObject(in);
            out.flush();
            return Base64.getEncoder().encodeToString(outBytes.toByteArray());
        } catch (IOException e) { throw new E(e); }
    }

    public static String generateKey() {
        KeyGenerator gen = null;
        try { gen = KeyGenerator.getInstance(KEY_ALGORITHM); } catch (NoSuchAlgorithmException e) { throw new E(e); }
        gen.init(KEY_SIZE); // for example
        var k = gen.generateKey();
        return encodeKey(k);
    }

    public String name;

    public Profile(DB db, Rec rec) { super(db.profile, rec); }
    public Profile(DB db) { super(db.profile); }
    public void initKey() { key = Profile.generateKey(); }

    public SecretKey key() {
        try {
            var decoded = Base64.getDecoder().decode(key.getBytes());
            var in = new ObjectInputStream(new ByteArrayInputStream(decoded));
            return (SecretKey)in.readObject();
        } catch (ClassNotFoundException | IOException e) { throw new E(e); }
    }

    private String key;
}
