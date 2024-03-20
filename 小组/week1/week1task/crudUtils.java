package week1task;

import java.sql.*;

public class crudUtils {
    private static Statement statement = null;
    private static ResultSet resultSet = null;
    private static Connection connection;

    static {
        connection = connectionUtils.mysqlConnection();
    }

    public static Connection getConnection() {
        return connection;
    }

    static public boolean create(String tablename, String columnLabel, String content) throws SQLException {
        String sql="insert into "+tablename;
        if(columnLabel!=null){
            sql=sql+" "+columnLabel+" ";
        }
        sql=sql+" values "+content;
        try {
            statement=connection.createStatement();
            System.out.println("执行成功");
            return statement.execute(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            statement.close();
        }


    }

    public static void read(String content, int amount, String tablename) throws SQLException {
        read(content, amount, tablename, null);
    }

    public static void read(String content, int amount, String tablename, String condition) throws SQLException {
        String sql = "select " + content + " from " + tablename;
        System.out.println(sql);
        if (condition != null) {
            sql = sql + " where " + condition;
            System.out.println(sql);
        }
        try {
            statement = connection.createStatement();
            resultSet = statement.executeQuery(sql);
            while (resultSet.next()) {
                int i = 0;
                while (i < amount)
                    System.out.print(resultSet.getObject(++i) + "\t");
                System.out.println();
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            statement.close();
            resultSet.close();
        }

    }

    static public int update(String tablename, String content, String condition) throws SQLException {
        String sql = "update " + tablename + " set " + content;
        if (condition != null)
            sql = sql + " where " + condition;
        try {
            statement = connection.createStatement();
            System.out.println("执行成功");
            return statement.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            statement.close();
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
