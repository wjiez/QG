package week1task;

import java.sql.SQLException;

public class test {
    public static void main(String[] args) throws SQLException {
        crudUtils.create("account",null,"(4,'wei','888888',3000,6,now())");
        crudUtils.read("*", 6, "account");
        System.out.println(crudUtils.update("account","password=666666","accname='wang'"));
        crudUtils.read("*",6,"account");
        crudUtils.delete("account","accid=4 or accid=5");
        connectionUtils.close(crudUtils.getConnection(),null,null);
    }
}
