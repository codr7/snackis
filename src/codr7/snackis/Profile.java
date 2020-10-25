package codr7.snackis;

import codr7.jappkit.E;
import codr7.jappkit.db.Mod;
import codr7.jappkit.db.Rec;

import java.io.*;
import java.security.*;
import java.util.Base64;

public class Profile extends Mod {
    public static final String KEY_ALGORITHM = "RSA";
    public static final int KEY_SIZE = 2048;

    public static Make<Profile> make(DB db) { return (rec) -> { return new Profile(db, rec); }; }

    public static String encodeKey(Key in) {
        var outBytes = new ByteArrayOutputStream();

        try {
            ObjectOutputStream out = new ObjectOutputStream(outBytes);
            out.writeObject(in);
            out.close();
            return Base64.getEncoder().encodeToString(outBytes.toByteArray());
        } catch (IOException e) { throw new E(e); }
    }

    public static KeyPair generateKey() {
        try {
            var g = KeyPairGenerator.getInstance(KEY_ALGORITHM);
            g.initialize(KEY_SIZE);
            return g.generateKeyPair();
        } catch (NoSuchAlgorithmException e) { throw new E(e); }
    }

    public String name;

    public Profile(DB db, Rec rec) { super(db.profile, rec); }
    public Profile(DB db) { super(db.profile); }

    public PublicKey key() {
        try {
            var decoded = Base64.getDecoder().decode(key.getBytes());
            var in = new ObjectInputStream(new ByteArrayInputStream(decoded));
            return (PublicKey)in.readObject();
        } catch (ClassNotFoundException | IOException e) { throw new E(e); }
    }

    public void setKey(PublicKey in) { key = encodeKey(in); }

    private String key;
}
