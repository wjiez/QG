package com.wei.service;

import com.wei.po.account;
import com.wei.utils.connectionUtils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class webService {
    private static Connection connection;
    static {
        connection = connectionUtils.mysqlConnection();
    }
    public static Boolean selectByAccName(String name) throws SQLException {
        Boolean flag=true;
        String sql = "select * from account where accname = ?";
        PreparedStatement pstmt=connection.prepareStatement(sql);
        pstmt.setString(1,name);
        ResultSet resultSet = pstmt.executeQuery();
        if(resultSet.next()){
            flag=true;
        }else{
            flag=false;
        }
        return flag;
    }
    public static Boolean checkAccount(account account) throws SQLException {
        Boolean flag=true;
        String sql ="select * from account where accname = ? and password = ?";
        PreparedStatement pstmt=connection.prepareStatement(sql);
        pstmt.setString(1,account.getAccname());
        pstmt.setString(2,account.getPassWord());
        System.out.println(sql);
        System.out.println(pstmt);
        ResultSet resultSet = pstmt.executeQuery();
        if(resultSet.next()){
            flag=true;
        }else{
            flag=false;
        }
        return flag;
    }

}
