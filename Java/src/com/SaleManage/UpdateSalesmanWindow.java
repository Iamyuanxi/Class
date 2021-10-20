package com.SaleManage;

import com.SaleManage.Entity.Salesman;
import com.SaleManage.Services.SalesmanService;
import com.SaleManage.Services.SalesmanServiceImpl;

import javax.swing.*;
import java.awt.*;

public class UpdateSalesmanWindow extends JDialog {
    JPanel jPanel = new JPanel(new FlowLayout(FlowLayout.CENTER,10,20));

    JLabel nameLabel = new JLabel("姓名",JLabel.RIGHT);
    JTextField nameTxt = new JTextField();

    JLabel numLabel = new JLabel("代号",JLabel.RIGHT);
    JTextField numTxt = new JTextField();

    JLabel genderLabel = new JLabel("性别",JLabel.RIGHT);
    JTextField genderTxt = new JTextField();

    JLabel birthLabel = new JLabel("出生年月",JLabel.RIGHT);
    JTextField birthTxt = new JTextField();

    JLabel phoneLabel = new JLabel("电话号码",JLabel.RIGHT);
    JTextField phoneTxt = new JTextField();

    JLabel addressLabel = new JLabel("居住地址",JLabel.RIGHT);
    JTextField addressTxt = new JTextField();

    JLabel dateLabel = new JLabel("入职时间",JLabel.RIGHT);
    JTextField dateTxt = new JTextField();

    JButton updateButton = new JButton("修改");

    UpdateSalesmanWindowHandler updateSalesmanWindowHandler;

    public UpdateSalesmanWindow(SalesmanManageWindow salesmanManageWindow, String selectedSalesmanNumber) {
        super(salesmanManageWindow,"修改销售员信息",true);
        updateSalesmanWindowHandler = new UpdateSalesmanWindowHandler(this,salesmanManageWindow);

        SalesmanService salesmanService = new SalesmanServiceImpl();
        Salesman selectSalesman = salesmanService.getByNumber(selectedSalesmanNumber);

        numLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(numLabel);
        numTxt.setPreferredSize(new Dimension(200,30));
        numTxt.setText(selectSalesman.getNumber());
        //设置num不可编辑
        numTxt.setEnabled(false);
        jPanel.add(numTxt);

        nameLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(nameLabel);
        nameTxt.setPreferredSize(new Dimension(200,30));
        nameTxt.setText(selectSalesman.getName());
        jPanel.add(nameTxt);

        genderLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(genderLabel);
        genderTxt.setPreferredSize(new Dimension(200,30));
        genderTxt.setText(selectSalesman.getGender());
        jPanel.add(genderTxt);

        birthLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(birthLabel);
        birthTxt.setPreferredSize(new Dimension(200,30));
        birthTxt.setText(selectSalesman.getBirthDate());
        jPanel.add(birthTxt);

        phoneLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(phoneLabel);
        phoneTxt.setPreferredSize(new Dimension(200,30));
        phoneTxt.setText(selectSalesman.getPhone());
        jPanel.add(phoneTxt);

        addressLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(addressLabel);
        addressTxt.setPreferredSize(new Dimension(200,30));
        addressTxt.setText(selectSalesman.getAddress());
        jPanel.add(addressTxt);

        dateLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(dateLabel);
        dateTxt.setPreferredSize(new Dimension(200,30));
        dateTxt.setText(selectSalesman.getEmployedDate());
        jPanel.add(dateTxt);

        updateButton.addActionListener(updateSalesmanWindowHandler);
        jPanel.add(updateButton);

        Container contentPane = getContentPane();
        contentPane.add(jPanel);
        setSize(350,500);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setResizable(false);
        setVisible(true);
    }

    public Salesman buildUpdateSalesman() {
        Salesman salesman = new Salesman();

        salesman.setNumber(numTxt.getText());
        salesman.setName(nameTxt.getText());
        salesman.setGender(genderTxt.getText());
        salesman.setBirthDate(birthTxt.getText());
        salesman.setPhone(phoneTxt.getText());
        salesman.setAddress(addressTxt.getText());
        salesman.setEmployedDate(dateTxt.getText());

        return salesman;
    }
}
