package service;

import com.alibaba.fastjson.JSON;
import util.accountCRUDUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/addService")
public class accountAdd extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //获取请求体
        BufferedReader br=req.getReader();
        String params=br.readLine();
        System.out.println(params);
        //Json数据转为Java对象
        account account= JSON.parseObject(params,account.class);
        //调用jdbc工具类添加
        accountCRUDUtils.insert(account);
        //响应成功
        resp.getWriter().write("success");
    }
}
