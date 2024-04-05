package util;

import service.account;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class accountCRUDUtils {
    private static Statement statement = null;
    private static ResultSet resultSet = null;
    private static Connection connection;


    static {
        connection = connectionUtils.mysqlConnection();
    }

    public static Connection getConnection() {
        return connection;
    }

    static public boolean insert(account account) {
        String sql="insert into account values("+account.getAccid()+",\'"+account.getAccname()+"\',\'"+account.getPassWord()+"\',\'"+account.getCity()+"\')";
        System.out.println(sql);
        try {
            statement=connection.createStatement();
            return statement.execute(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    public static List<account> selectAll(){
        List<account> accounts=new ArrayList<>();
        String sql = "select * from account";
        try {
            statement = connection.createStatement();
            resultSet = statement.executeQuery(sql);
            while (resultSet.next()) {
                int i=0;
                account account = new account();
                account.setAccid(resultSet.getInt(++i));
                account.setAccname(resultSet.getString(++i));
                account.setPassWord(resultSet.getString(++i));
                account.setCity(resultSet.getString(++i));
                accounts.add(account);
            }
            return accounts;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    static public int update(String tablename, String content, String condition) {
        String sql = "update " + tablename + " set " + content;
        if (condition != null)
            sql = sql + " where " + condition;
        try {
            statement = connection.createStatement();
            System.out.println("执行成功");
            return statement.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    static public void delete(String tablename, String condition) throws SQLException {
        String sql = "delete from " + tablename;
        if (condition != null) {
            sql = sql + " where " + condition;
        }
        try {
            statement = connection.createStatement();
            System.out.println(sql);
            statement.execute(sql);
            System.out.println("执行成功");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            statement.close();
        }
    }


}
