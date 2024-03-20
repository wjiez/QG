package week1task;

import java.sql.*;

public class connectionUtils {
    private static String user = "root";
    private static String password = "123123";
    private static String url = "jdbc:mysql://localhost:3306/bank";
    private static String driver = "com.mysql.cj.jdbc.Driver";

    public static Connection mysqlConnection() {
        Connection connection = null;
        try {
            Class.forName(driver);
            connection = DriverManager.getConnection(url, user, password);
        } catch (Exception e) {
            throw new RuntimeException();
        }
        return connection;
    }

    public static void close(Connection connection, Statement statement, ResultSet resultset) {
        if (resultset != null) {
            try {
                resultset.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        if (statement != null) {
            try {
                statement.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
