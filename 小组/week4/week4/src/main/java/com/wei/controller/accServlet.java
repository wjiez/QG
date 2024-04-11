package com.wei.controller;

import com.alibaba.fastjson.JSON;
import com.wei.po.account;
import com.wei.dao.accountCRUD;
import com.wei.service.webService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

@WebServlet("/account/*")
public class accServlet extends BaseServlet {
    public void selectAccName(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException, SQLException {
        BufferedReader br = req.getReader();
        String accname = br.readLine();
        if (webService.selectByAccName(accname)) {
            resp.getWriter().write("true");
        } else {
            resp.getWriter().write("false");
        }
    }

    public void accRegister(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException, SQLException {
        BufferedReader br = req.getReader();
        String params = br.readLine();
        //Json数据转为Java对象
        account account = JSON.parseObject(params, account.class);
        if (webService.selectByAccName(account.getAccname())) {
            resp.getWriter().write("duplicate");
        } else {
            resp.getWriter().write("success");
            accountCRUD.insert(account);
        }
    }

    public void checkAccount(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException, SQLException {
        //获取请求体
        BufferedReader br = req.getReader();
        String params = br.readLine();
        //Json数据转为Java对象
        account account = JSON.parseObject(params, account.class);
        //调用service查找用户密码
        if (webService.checkAccount(account)) {
            resp.getWriter().write("success");//响应成功
        } else {
            resp.getWriter().write("false");
        }
    }
}
