package util;

import java.sql.*;

public class connectionUtils {
    private static final String user = "root";
    private static final String password = "123wjz123";
    private static final String url = "jdbc:mysql://localhost:3306/bank";
    private static final String driver = "com.mysql.cj.jdbc.Driver";

    public static Connection mysqlConnection() {
        Connection connection;
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
