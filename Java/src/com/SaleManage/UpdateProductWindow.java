package com.SaleManage;

import com.SaleManage.Entity.ProductInformation;
import com.SaleManage.Services.ProductService;
import com.SaleManage.Services.ProductServiceImpl;

import javax.swing.*;
import java.awt.*;

public class UpdateProductWindow extends JDialog {
    JPanel jPanel = new JPanel(new FlowLayout(FlowLayout.CENTER,10,20));

    JLabel nameLabel = new JLabel("名称",JLabel.RIGHT);
    JTextField nameTxt = new JTextField();

    JLabel codeLabel = new JLabel("编码",JLabel.RIGHT);
    JTextField codeTxt = new JTextField();

    JLabel numLabel = new JLabel("总数",JLabel.RIGHT);
    JTextField numTxt = new JTextField();

    JLabel priceLabel = new JLabel("进价",JLabel.RIGHT);
    JTextField priceTxt = new JTextField();

    JLabel producerLabel = new JLabel("厂商",JLabel.RIGHT);
    JTextField producerTxt = new JTextField();

    JLabel dateLabel = new JLabel("入库时间",JLabel.RIGHT);
    JTextField dateTxt = new JTextField();

    JButton updateButton = new JButton("修改");

    UpdateProductWindowHandler updateProductWindowHandler;

    public UpdateProductWindow(ProductManageWindow productManageWindow, String selectedProductName) {
        super(productManageWindow,"修改产品信息",true);
        updateProductWindowHandler = new UpdateProductWindowHandler(this, productManageWindow);
        //查询selectedProductName对应的记录并回显
        ProductService productService = new ProductServiceImpl();
        ProductInformation selectProduct = productService.getByName(selectedProductName);

        nameLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(nameLabel);
        nameTxt.setPreferredSize(new Dimension(200,30));
        nameTxt.setText(selectProduct.getName());
        //设置name不可编辑
        nameTxt.setEnabled(false);
        jPanel.add(nameTxt);

        codeLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(codeLabel);
        codeTxt.setPreferredSize(new Dimension(200,30));
        codeTxt.setText(selectProduct.getCode());
        jPanel.add(codeTxt);

        numLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(numLabel);
        numTxt.setPreferredSize(new Dimension(200,30));
        numTxt.setText(String.valueOf(selectProduct.getTotalNumber()));
        jPanel.add(numTxt);

        priceLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(priceLabel);
        priceTxt.setPreferredSize(new Dimension(200,30));
        priceTxt.setText(String.valueOf(selectProduct.getUnitPrice()));
        jPanel.add(priceTxt);

        producerLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(producerLabel);
        producerTxt.setPreferredSize(new Dimension(200,30));
        producerTxt.setText(selectProduct.getProducer());
        jPanel.add(producerTxt);

        dateLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(dateLabel);
        dateTxt.setPreferredSize(new Dimension(200,30));
        dateTxt.setText(selectProduct.getStockDate());
        jPanel.add(dateTxt);

        updateButton.addActionListener(updateProductWindowHandler);
        jPanel.add(updateButton);

        Container contentPane = getContentPane();
        contentPane.add(jPanel);
        setSize(350,500);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setResizable(false);
        setVisible(true);
    }

    //获取修改后的产品信息对象
    public ProductInformation buildUpdateProduct() {
        ProductInformation productInformation = new ProductInformation();

        productInformation.setName(nameTxt.getText());
        productInformation.setCode(codeTxt.getText());
        productInformation.setTotalNumber(Integer.valueOf(numTxt.getText()));
        productInformation.setUnitPrice(Double.valueOf(priceTxt.getText()));
        productInformation.setProducer(producerTxt.getText());
        productInformation.setStockDate(dateTxt.getText());

        return productInformation;
    }
}
