package codr7.snackis;

import codr7.jappkit.db.Mod;
import codr7.jappkit.db.Rec;
import codr7.jappkit.db.Ref;

public class Peer extends Mod {
    public static Make<Peer> make(DB db) { return (rec) -> { return new Peer(db, rec); }; }

    public Peer(DB db, Rec rec) { super(db.peer, rec); }
    public Peer(DB db) { super(db.peer); }

    private Ref<Profile> profile;
    private String address;
    private Long port;
}
