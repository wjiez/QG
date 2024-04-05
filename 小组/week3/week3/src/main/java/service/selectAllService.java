package service;

import com.alibaba.fastjson.JSON;
import util.accountCRUDUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/selectAllService")
public class selectAllService extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        //JDBC获得数据
        List<account> accounts = accountCRUDUtils.selectAll();
        //转换数据
        String jsonString = JSON.toJSONString(accounts);
        //设置字符集
        resp.setContentType("text/json;charset=utf-8");
        //响应数据
        resp.getWriter().write(jsonString);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }
}
