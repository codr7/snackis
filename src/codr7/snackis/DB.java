package codr7.snackis;

import codr7.jappkit.db.Index;
import codr7.jappkit.db.Schema;
import codr7.jappkit.db.Table;
import codr7.jappkit.db.column.LongCol;
import codr7.jappkit.db.column.RefCol;
import codr7.jappkit.db.column.StringCol;
import codr7.jappkit.demo.bookr.Product;

import java.nio.file.Path;

public class DB extends Schema {
    public final Table profile = new Table(this, "profile");
    public final StringCol profileName = new StringCol(profile, "name");
    public final StringCol profileKey = new StringCol(profile, "key");
    public final Index profileNameIndex = new Index(this, "profile_name", profileName);
    public final Index profileKeyIndex = new Index(this, "profile_key", profileKey);

    public final Table peer = new Table(this, "peer");
    public final RefCol<Profile> peerProfile = new RefCol<Profile>(peer, "profile", profile, Profile.make(this));
    public final StringCol peerAddress = new StringCol(peer, "address");
    public final LongCol peerPort = new LongCol(peer, "port");

    public DB(Path root) {
        super(root);
        profile.addIndex(profileNameIndex);
        profile.addIndex(profileKeyIndex);
    }
}