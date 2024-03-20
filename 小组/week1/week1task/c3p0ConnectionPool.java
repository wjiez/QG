package com.wjz.databaseConnection;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import java.beans.PropertyVetoException;
import java.sql.Connection;
import java.sql.SQLException;

public class c3p0ConnectionPool {
   public static void main(String[] args) throws SQLException, PropertyVetoException {
       ComboPooledDataSource dataSource= new ComboPooledDataSource();
       dataSource.setDriverClass("com.mysql.cj.jdbc.Driver");
       dataSource.setUser("root");
       dataSource.setPassword("123wjz123");
       dataSource.setJdbcUrl("jdbc:mysql://localhost:3306/bank");
       dataSource.setInitialPoolSize(1);
       dataSource.setMaxPoolSize(1);
       Connection connection = null;
       try {
           connection = dataSource.getConnection();
       } catch (SQLException e) {
           throw new RuntimeException(e);
       }finally {
           connection.close();
       }

   }
}
