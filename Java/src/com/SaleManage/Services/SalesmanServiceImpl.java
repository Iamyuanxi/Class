package com.SaleManage.Services;

import com.SaleManage.Entity.Salesman;
import com.SaleManage.Request;
import com.SaleManage.TableDTO;
import com.SaleManage.util.DatabaseLink;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

public class SalesmanServiceImpl implements SalesmanService {
    @Override
    public TableDTO retrieveSalesmans(Request request) {
        StringBuilder sql = new StringBuilder();

        sql.append("select * from salesmanage.salesman");

        if (request.getSearchKey() != null && !"".equals(request.getSearchKey().trim())) {
            sql.append(" where name like '%").append(request.getSearchKey().trim()).append("%'");
        }

        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        TableDTO returnDTO = new TableDTO();

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());
            rs = ps.executeQuery();
            //查询记录
            returnDTO.setData(fillData(rs));

            return returnDTO;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closeRs(rs);
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return null;
    }

    @Override
    public boolean add(Salesman salesman) {
        StringBuilder sql = new StringBuilder();

        sql.append("insert into salesmanage.salesman (number, name, gender, birthDate, phone, address, employedDate) ");
        sql.append(" values(?,?,?,?,?,?,?)");

        Connection conn = null;
        PreparedStatement ps = null;

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());
            ps.setString(1,salesman.getNumber());
            ps.setString(2,salesman.getName());
            ps.setString(3,salesman.getGender());
            ps.setString(4,salesman.getBirthDate());
            ps.setString(5,salesman.getPhone());
            ps.setString(6,salesman.getAddress());
            ps.setString(7,salesman.getEmployedDate());

            return ps.executeUpdate() == 1;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return false;
    }

    @Override
    public Salesman getByNumber(String selectedSalesmanNumber) {
        StringBuilder sql = new StringBuilder("select * from salesmanage.salesman where number=?");

        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;

        Salesman salesman = new Salesman();

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());
            ps.setString(1,selectedSalesmanNumber);
            rs = ps.executeQuery();

            while (rs.next()) {
                String number = rs.getString("number");
                String name = rs.getString("name");
                String gender = rs.getString("gender");
                String birthDate = rs.getString("birthDate");
                String phone = rs.getString("phone");
                String address = rs.getString("address");
                String employedDate = rs.getString("employedDate");

                salesman.setNumber(number);
                salesman.setName(name);
                salesman.setGender(gender);
                salesman.setBirthDate(birthDate);
                salesman.setPhone(phone);
                salesman.setAddress(address);
                salesman.setEmployedDate(employedDate);
            }

            return salesman;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closeRs(rs);
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return null;
    }

    @Override
    public boolean update(Salesman salesman) {
        StringBuilder sql = new StringBuilder();

        sql.append("update salesmanage.salesman set name=?,gender=?,birthDate=?,phone=?,address=?,employedDate=? ");
        sql.append(" where number=?");

        Connection conn = null;
        PreparedStatement ps = null;

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());

            ps.setString(1,salesman.getName());
            ps.setString(2,salesman.getGender());
            ps.setString(3,salesman.getBirthDate());
            ps.setString(4,salesman.getPhone());
            ps.setString(5,salesman.getAddress());
            ps.setString(6,salesman.getEmployedDate());
            ps.setString(7,salesman.getNumber());

            return ps.executeUpdate() == 1;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return false;
    }

    @Override
    public boolean delete(String[] numbers) {
        StringBuilder sql = new StringBuilder();

        sql.append("delete from salesmanage.salesman where number in (");

        int length = numbers.length;

        for (int i=0; i<length; ++i) {
            if (i == (length-1)) {
                sql.append("? )");
            } else {
                sql.append("?, ");
            }
        }

        Connection conn = null;
        PreparedStatement ps = null;

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());

            for (int i=0; i<length; i++) {
                ps.setString(i + 1, numbers[i]);
            }

            return ps.executeUpdate() == length;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return false;
    }

    private Vector<Vector<Object>> fillData(ResultSet rs) throws SQLException {
        Vector<Vector<Object>> data = new Vector<>();

        while (rs.next()) {
            Vector<Object> record = new Vector<>();
            //处理查出的每天记录
            String number = rs.getString("number");
            String name = rs.getString("name");
            String gender = rs.getString("gender");
            String birthDate = rs.getString("birthDate");
            String phone = rs.getString("phone");
            String address = rs.getString("address");
            String employedDate = rs.getString("employedDate");

            record.addElement(number);
            record.addElement(name);
            record.addElement(gender);
            record.addElement(birthDate);
            record.addElement(phone);
            record.addElement(address);
            record.addElement(employedDate);

            data.addElement(record);
        }

        return data;
    }
}
